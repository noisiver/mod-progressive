#!/usr/bin/env bash
MOD_PROGRESSIVE_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )/" && pwd )"

source $MOD_PROGRESSIVE_ROOT"/conf/conf.sh.dist"

if [ -f $MOD_PROGRESSIVE_ROOT"/conf/conf.sh" ]; then
    source $MOD_PROGRESSIVE_ROOT"/conf/conf.sh"
fi
