#!/bin/bash

docker run -it  --mount type=bind,src="$(pwd)/src",target=/app myzmqimage bash
