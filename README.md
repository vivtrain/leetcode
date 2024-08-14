# leetcode
A collection of all my data structures and algorithms practice as of July 2024.
This is in preparation for my first full-time employment opportunities after
having graduated with a bachelor's degree.

## Grind 75
I've chosen to use the [Grind 75](https://www.techinterviewhandbook.org/grind75)
problem set from the Tech Interview Handbook. In my opinion, it is a good place
to start practicing DSA questions. After doing these, I will select
miscellaneous or domain-specific questions to study.

## Nice Things
### Spinup
In the `Grind75/` directory, there is a brief script called `spinup` that
sets up a few relevant files for a small, self-contained C++ program and a small
self-contained Python3 program. Usage looks something like

```
. spinup 1 TwoSum
```

and results in the following file structure.

```
1-TwoSum/
|-- cpp
|   |-- TwoSum.cpp
|   |-- TwoSum.h
|   |-- makefile
|   `-- test.cpp
`-- python
    `-- TwoSum.py
```

The script also creates a `.ycm_extra_conf` in the `cpp/` directory for adding
custom flags for the vim plugin
[YouCompleteMe](https://github.com/ycm-core/YouCompleteMe) and a vim session for
the `cpp/` directory.

### Utility
In the `Grind75/` directory, I've created a `Utility` directory to which I can
add common functions and data structures as I go to reduce code duplication.
The `makefile` is setup with some variables with which C++ programs can be
properly compiled, and the Python script contains a call to `sys.path.append`
including the appropriate directory.
