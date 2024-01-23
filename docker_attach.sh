#!/bin/bash

docker attach $(docker container ls  --quiet)
