'''Recipe to create either a docker container or Singularity image
for a compute node on which users can log in using password authentication.
The SQS queue system is available as well as a number of editors, git,
make, CMake, GCC and Open-MPI

Usage:
    $ hpccm  --recipe development_c++.py  --format docker
    $ hpccm  --recipe development_c++.py  --format singularity
'''

from pathlib import Path


# Choose a base image
Stage0.baseimage('ubuntu:24.10')
 
# Install editor and other tools
Stage0 += apt_get(ospackages=[
    'vim',
    'neovim',
    'less',
    'ack',
    'tmux',
    'tar',
    'gzip',
    'bzip2',
    'wget',
    'ca-certificates',
])

# Install pip
Stage0 += apt_get(ospackages=['python3-pip', ])

# Install version control
Stage0 += apt_get(ospackages=['git', 'openssh-client', ])

# Install build tools
Stage0 += apt_get(ospackages=[
    'build-essential',
    'autotools-dev',
    'make',
    'pkg-config',
    'ninja-build',
])
Stage0 += cmake(eula=True, prefix='/usr/', version='3.31.6')

# Install compilers (upstream)
Stage0 += gnu()
Stage0 += llvm(toolset=True, upstream=True)

# install Open-MPI
# This is the right thing to do, but it takes forever since it actually
# builds Open MPI from source
# Stage0 += openmpi(cuda=False, infiniband=False, version='4.0.2',
#                  toolchain=compilers.toolchain, prefix='/usr/local/')
# Fetching form repository is faster
# Stage0 += apt_get(ospackages=['libopenmpi-dev', 'openmpi-common', 'openmpi-bin'])

# Install debugging tools and software engineering tools
Stage0 += apt_get(ospackages=[
    'gdb',
    'valgrind',
    'strace',
    'cppcheck',
    'clang-tidy',
    'catch2',
    'doxygen',
    'hyperfine',
])

# Install C++ libraries
Stage0 += apt_get(ospackages=[
    'libopenblas-openmp-dev',
    'liblapack64-dev', 
    'libarmadillo-dev',
    'libeigen3-dev',
    'libboost-all-dev',
])

# Run a bash shell by default
Stage0 += runscript(commands=['/bin/bash'])

# Copy in some example code
# source_dir = Path('source-code')
# example_dir = '/sample_code'
# for file in source_dir.glob('*'):
#     Stage0 += copy(src=f'{file}',
#                    dest=f'{example_dir}/',
#                    _mkdir=True)
