#!/bin/bash

task="train"
stack_size=268435456  # 256 MB

ulimit -s "${stack_size}"
"./${task}"

