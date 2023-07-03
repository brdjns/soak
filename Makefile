# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2023 Bradley Jones <brdjns@gmx.us

CXXFLAGS = -O2 -Wall -Wextra -Wpedantic -std=c++14 -march=native

all: soak

soak: soak.cc

clean:
	rm soak