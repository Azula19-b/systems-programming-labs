# Systems Programming Labs

A collection of small C, Bash, `sed`, `gawk`, process-control, networking, and
lexical-analysis exercises. Each directory focuses on one systems programming
concept and can be explored independently.

## Lab index

| Directory | Topics |
| --- | --- |
| `rec01-c-basics` | ASCII values, hexadecimal output, and bit operations |
| `rec02-dynamic-memory` | `malloc`, input validation, XOR swapping, and `free` |
| `rec04-sed` | Pattern matching and stream editing practice data |
| `rec05-gawk` | Record, field, and process-list queries with GNU Awk |
| `rec06-shell-scripting` | Arguments, command execution, and a guessing game |
| `rec07-bash-arrays` | Functions, arrays, input validation, and grade curves |
| `rec08-processes` | `fork`, `exec`, waiting, zombie processes, and orphans |
| `rec11-networking` | A basic IPv4 TCP client and server |
| `lexer` | A Flex scanner for identifiers, numbers, and calculator operators |

## Requirements

- Linux, macOS, WSL, or another POSIX-like environment
- A C11-compatible compiler
- Make
- Bash
- `sed` and `gawk` for the text-processing labs
- Flex plus the course parser header `zcalc.h` for the lexer exercise

## Build the C exercises

```bash
make
```

Compiled programs are placed in `bin/`:

```text
bin/ascii_binary
bin/ascii_binary_alternate
bin/dynamic_memory_swap
bin/process_exec
bin/process_zombie
bin/process_orphan
bin/tcp_client
bin/tcp_server
```

The lexer is not part of the default build because its original companion
header, `zcalc.h`, is not present in the source collection.

## Run examples

ASCII and bit representation:

```bash
./bin/ascii_binary
```

Dynamic allocation and swapping:

```bash
./bin/dynamic_memory_swap
```

Shell exercises:

```bash
bash rec06-shell-scripting/rec06A.sh Ada
bash rec06-shell-scripting/rec06C.sh
bash rec07-bash-arrays/rec07.sh 5
```

TCP networking uses two terminals. Start the server first:

```bash
./bin/tcp_server 5001
```

Then connect with the client:

```bash
./bin/tcp_client 5001
```

## Validate shell scripts

```bash
make check-shell
```

## Clean build output

```bash
make clean
```

## Notes

Some process examples intentionally create short-lived zombie or orphan
processes for observation. Run them only in a disposable terminal session.
The files in the `sed` and `gawk` directories are learning artifacts and input
data rather than standalone applications.
