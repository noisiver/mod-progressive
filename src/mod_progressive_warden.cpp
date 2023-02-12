#include "Config.h"
#include "WorldSession.h"

#include "mod_progressive.h"

std::string _prePayload = "wlbuf = '';";
std::string _postPayload = "loadstring(wlbuf)();wlbuf = nil;";
uint16 _prePayloadId = 5500;
uint16 _postPayloadId = 5501;
uint16 _tmpPayloadId = 5502;

bool Progressive::CanPacketSend(WorldSession* session, WorldPacket& packet)
{
    WardenWin* warden = (WardenWin*)session->GetWarden();
    if (!warden)
        return true;

    auto payloadMgr = warden->GetPayloadMgr();
    if (!payloadMgr)
        return true;

    if (EnablePatchNotes)
    {
        if (packet.GetOpcode() == SMSG_CHAR_ENUM)
        {
            std::string payload = Acore::StringFormatFmt("ServerAlertTitle:SetText('{}');local saf = ServerAlertFrame;saf:SetParent(CharacterSelect);ServerAlertText:SetText('{}');saf:Show();", PatchNotes[PatchId][0], PatchNotes[PatchId][1]);
            payloadMgr->ClearQueuedPayloads();
            SendChunkedPayload(warden, payload, 128);
        }
    }

    if (packet.GetOpcode() == SMSG_LOGIN_VERIFY_WORLD)
    {
        std::string payload = Acore::StringFormatFmt("SetCVar(\"showQuestTrackingTooltips\", 1);");
        if (PatchId < FALL_OF_THE_LICH_KING && !EnableQuestPOI)
            payload = Acore::StringFormatFmt("SetCVar(\"showQuestTrackingTooltips\", 0);");
        payloadMgr->ClearQueuedPayloads();
        SendChunkedPayload(warden, payload, 128);
    }

    return true;
}

std::vector<std::string> Progressive::GetChunks(std::string s, uint8_t chunkSize)
{
    std::vector<std::string> chunks;

    for (uint32_t i = 0; i < s.size(); i += chunkSize)
        chunks.push_back(s.substr(i, chunkSize));

    return chunks;
}

void Progressive::SendChunkedPayload(Warden* warden, std::string payload, uint32 chunkSize)
{
    auto payloadMgr = warden->GetPayloadMgr();
    if (!payloadMgr)
        return;

    auto chunks = GetChunks(payload, chunkSize);

    if (!payloadMgr->GetPayloadById(_prePayloadId))
        payloadMgr->RegisterPayload(_prePayload, _prePayloadId);

    payloadMgr->QueuePayload(_prePayloadId);
    warden->ForceChecks();

    for (auto const& chunk : chunks)
    {
        auto smallPayload = "wlbuf = wlbuf .. [[" + chunk + "]];";

        payloadMgr->RegisterPayload(smallPayload, _tmpPayloadId, true);
        payloadMgr->QueuePayload(_tmpPayloadId);
        warden->ForceChecks();
    }

    if (!payloadMgr->GetPayloadById(_postPayloadId))
        payloadMgr->RegisterPayload(_postPayload, _postPayloadId);

    payloadMgr->QueuePayload(_postPayloadId);
    warden->ForceChecks();
}
