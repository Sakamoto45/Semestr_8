TEMPLATE = subdirs

#include(./src/lib/lib.pri)

  SUBDIRS = \
#            lib \   # sub-project names
            cli

  # where to find the sub projects - give the folders
#  lib.subdir = src/lib
  cli.subdir = src/cli


  # what subproject depends on others
#  cli.depends = lib



#CONFIG+= ordered
