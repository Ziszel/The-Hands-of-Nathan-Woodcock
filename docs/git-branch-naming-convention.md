# Git Branch Name Convention

## Overview

The purpose of this document is to help anyone understand the logic behind, how to read and understand,
and ultimately work with the branch structure that has been put in place to help organise code tasks
in the source code.

Most branches will be based upon a task specified in the Trello board; sometimes this is not the case,
usually due to a small fix as part of a bigger update (for example a spelling mistake in a document).

### Example

For those looking to jump straight in:

All characters should be lower-case, include no numbers and include no special characters:

- fix/character-cant-jump
- feature/menu-system-implementation
- docs/elaborate-further-on-inspiration-section

## Make-up of the branch structure

### Purpose Word

The Purpose Word, which is always one word,  describes what this branch is all about.
This word comes from an approved list, which is made up of the following:

- feature: A brand new feature currently not in the game.
- update: An update to a previous feature, or a bugfix.
- refactor: A unique branch. Description text is always a date. Only branch allowed to be worked on when active.

### The Description Text

The Description Text is a free space with each word separated by hyphens '-' that enables a developer
to explain in further detail what the branch is targetting.

For example:

- feature/initial-menu-system-implementation
- update/add-mouse-control-to-menu-system
- update/clicking-RMB-in-menu-crashes-game
