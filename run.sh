#!/usr/bin/env bash

EXECUTABLE_NAME="L"

if [ ! -f "./build/bin/${EXECUTABLE_NAME}" ]; then
    echo "Executable not found: ${EXECUTABLE_NAME}"
    exit 1
fi

./build/bin/${EXECUTABLE_NAME} ${@}
