#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/madhuprana/cognitive/Relay_node/relayforward/gr-howto/lib
export GR_CONF_CONTROLPORT_ON=False
export PATH=/home/madhuprana/cognitive/Relay_node/relayforward/gr-howto/build/lib:$PATH
export LD_LIBRARY_PATH=/home/madhuprana/cognitive/Relay_node/relayforward/gr-howto/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$PYTHONPATH
test-howto 
