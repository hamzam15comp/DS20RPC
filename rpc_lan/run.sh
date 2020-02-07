#!/bin/bash

for i in {0..125}
do
	./rpc_client 10.128.0.33
	sleep 60 
done

