<p align="center">
	<img src="https://img.shields.io/badge/status-ongoing-success?color=%2312bab9&style=flat-square"/>
	<img src="https://img.shields.io/github/languages/top/jotavare/leetcode?color=%2312bab9&style=flat-square"/>
	<img src="https://img.shields.io/github/last-commit/jotavare/leetcode?color=%2312bab9&style=flat-square"/>
	<a href='https://www.linkedin.com/in/jotavare' target="_blank"><img alt='Linkedin' src='https://img.shields.io/badge/LinkedIn-blue?style=flat-square'/></a>
	<a href='https://leetcode.com/u/jotavare/' target="_blank"><img alt='LeetCode' src='https://img.shields.io/badge/LeetCode-orange?style=flat-square'/></a>
</p>

<p align="center">
	<a href="#about">About</a> •
	<a href="#solutions">Solutions</a> •
	<a href="#examples">Examples</a> •
	<a href="#usage">Usage</a> •
	<a href="#contributing">Contributing</a> •
	<a href="#license">License</a>
</p>

## ABOUT

My solved [LeetCode](https://leetcode.com/u/jotavare/) problems, alongside a set
of small C programs I wrote while learning threads and linked lists.

The solutions are kept as LeetCode submits them: a bare `Solution` class or
function, with no `main` and no includes, since the site supplies both.

## SOLUTIONS

| # | Problem | Language |
| :-- | :-- | :-- |
| 1 | Two Sum | C++ |
| 9 | Palindrome Number | C++ |
| 13 | Roman to Integer | C++ |
| 21 | Merge Two Sorted Lists | C++ |
| 27 | Remove Element | C++ |
| 58 | Length of Last Word | C++ |
| 192 | Word Frequency | Bash |
| 193 | Valid Phone Numbers | Bash |
| 194 | Transpose File | Bash |
| 195 | Tenth Line | Bash |
| 283 | Move Zeroes | C++ |
| 345 | Reverse Vowels of a String | C |
| 605 | Can Place Flowers | C |
| 1768 | Merge Strings Alternately | C++ |

## EXAMPLES

Standalone programs under `examples/`, each one building and running on its own.

| File | What it shows |
| :-- | :-- |
| `pthreads.c` | Creating a thread and waiting for it |
| `pthread_join.c` | Joining, and what a return value looks like |
| `arguments_threads.c` | Passing data into a thread safely |
| `loop_threads.c` | Spawning threads in a loop |
| `race_condition.c` | The same counter without a lock |
| `pthread_mutex.c` | The same counter with one |
| `trylock_vs_lock.c` | Blocking versus returning immediately |
| `condition_variables.c` | Waiting on a condition instead of spinning |
| `cond_signal_vs_cond_broadcast.c` | Waking one waiter versus all of them |
| `processes_vs_threads.c` | `fork` against `pthread_create` |
| `linked_lists.c` | Building, searching and freeing a singly linked list |

## USAGE

The solutions are written for LeetCode's editor and are pasted there rather than
run locally. The examples build on their own:

```bash
cc -Wall -Wextra -pthread examples/pthread_mutex.c -o pthread_mutex
./pthread_mutex
```

The shell solutions read `file.txt` (or `words.txt` for 192), which is the name
LeetCode gives the input:

```bash
printf 'the day is sunny the the\nthe sunny is is\n' > words.txt
bash "leetcode/192. Word Frequency.sh"
```

## CONTRIBUTING

This repository holds finished exercises and is not open to changes.

## LICENSE

This project is available under the MIT License. For further details, please refer to the [LICENSE](https://github.com/jotavare/leetcode/blob/main/LICENSE) file.
