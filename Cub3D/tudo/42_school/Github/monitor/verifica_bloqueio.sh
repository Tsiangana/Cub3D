#!/bin/bash

while true; do
    bloqueada=$(loginctl show-session $(loginctl | grep $(whoami) | awk '{print $1}') -p LockedHint)
    
    if echo $bloqueada | grep -q "yes"; then
        echo "Tela bloqueada!"
    fi
    
    sleep 2
done

