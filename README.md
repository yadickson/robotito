# robotito

Un jueguito para aprender a mover un robot en un tablero

## required

- autoconf
- autoconf-archive
- automake
- libtool
- pkg-config
- libcpputest-dev
- libncurses-dev
- lcov
- cppcheck
- clang-format, clang-tidy (llvm)

## configuration

```bash
autoreconf -ivf
```

```bash
./configure
```

## build

```bash
make
```

## format

```bash
make format
```

## lint

```bash
make lint
```

## check

```bash
make check
```

## distcheck

```bash
make distcheck
```

## test

```bash
make test
```

## coverage

```bash
make coverage
```

## run

```bash
./src/robotito
```

