# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this repository is

A personal learning log: Python solutions to DSA practice problems plus Markdown study
notes (C# OOP, design patterns, SQL). There is no application, no build, no package
manifest, no test suite and no linter.

The `CLAUDE.md` in the parent directory (`source/repos/`) describes an unrelated
release-artifact repo (ABC client MSIs, checksums, Azure pipelines). None of it applies
here.

## Running code

Each `.py` file is standalone (stdlib only). Run one with:

```
python sde_sheet/arrays/04.kadanes_algorithm/kadanes_algorithm_b.py
```

Most files end with an ad-hoc call such as `Solution().maxSubArray([...])` or
`temp = Solution().generate_row(7)` that **does not print**, so running a file shows
nothing. Wrap the call in `print(...)` or use `python -i <file>` to inspect results.

## Layout and conventions

- **`sde_sheet/<topic>/NN.<problem_name>/`**: one folder per problem, with a two-digit
  zero-padded prefix for ordering (folders were renamed from `1.` to `01.` to keep sort
  order; follow that format).
  - Alternative solutions to the same problem sit side by side as `<name>_a.py`,
    `<name>_b.py`, `<name>_c.py`, ...
  - Solutions use LeetCode style: `class Solution` with the LeetCode method signature,
    usually `from typing import *`. Line 1 is often a `#` comment with the problem URL.
- **Root-level `.py` files** (`maximize_the_revenue.py`, `signal_ping.py`): one-off
  problems not part of the SDE sheet. Line 1 links the source conversation.
- **`oop/`**: C# OOP notes, one file per pillar (`01.encapsulation.md` ...
  `04.polymorphism.md`) plus `README.md` overview. This split version is current. The
  root `oop.md` is the older single-file version and has not been updated since the split.
- **`design_patterns/{creational,structural,behavioral}/NN.<pattern>.md`**: C# examples.
  Most files are stubs (a title, a one-line definition and an external reference link).
  Only `creational/01.singleton.md` is fully written.
- **`sql/`**: `README.md` holds the content. `01.DDL.md`, `02.DML.md` and `03.DQL.md` are
  empty placeholders.

Note style: `# TITLE` heading, bolded term definition, `###` subsections, fenced code
blocks tagged `csharp`/`cs` (both are used) or `sql`.

## Gotchas

- `.gitignore` still has entries from an earlier C++ phase (CMake, `.idea/`, `TEST.cpp`,
  `*.exe`). It also ignores **`*.sh`**, so shell scripts you add will not be committed
  unless the ignore rule is changed.
