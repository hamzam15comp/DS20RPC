#!/bin/bash

for i in {0..125}
do
	./rpc_client localhost
	sleep 60 
done

