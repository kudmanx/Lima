############################################################################
# This file is part of LImA, a Library for Image Acquisition
#
# Copyright (C) : 2009-2011
# European Synchrotron Radiation Facility
# BP 220, Grenoble 38043
# FRANCE
#
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, see <http://www.gnu.org/licenses/>.
############################################################################
LIMA_DIR := $(shell pwd)/../../..

ct-objs := SoftOpInternalMgr.o SoftOpExternalMgr.o SoftOpId.o

SRCS = $(ct-objs:.o=.cpp) 

CPPFLAGS = -I../include \
	   -I$(LIMA_DIR)/third-party/Processlib/core/include \
	   -I$(LIMA_DIR)/third-party/Processlib/tasks/include \
	   -I$(LIMA_DIR)/common/include
CXXFLAGS = -fPIC -Wall -pthread -g

all: CtSoftwareOperation.o


CtSoftwareOperation.o: $(ct-objs)
	ld -o $@ -r $+

clean:
	rm -f CtSoftwareOperation.o $(ct-objs) *.P

%.o : %.cpp
	$(COMPILE.cpp) $(CPPFLAGS) -MD $(CXXFLAGS) -o $@ $<
	@cp $*.d $*.P; \
	sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
	-e '/^$$/ d' -e 's/$$/ :/' < $*.d >> $*.P; \
	rm -f $*.d

-include $(SRCS:.cpp=.P)


.PHONY: check-syntax
check-syntax:
	$(CXX) $(CPPFLAGS) -Wextra -fsyntax-only $(CXXFLAGS) $(CHK_SOURCES)
