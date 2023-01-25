#!/bin/sh
# Don't forget to `make git-submodule` after first download
# Compile and flash my keymap to my atreus
make PCBDOWN=yes atreus:david:avrdude
