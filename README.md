# Skylake Proto

#### Connection oriented, best effort, UDP based protocol

### Features:
 - **Connection oriented**
    - Soft connection, used to produce a stable UDP channel (UDP holepunching)
    - The client is responsible for keepalives
 - **Best effort**
    - Not reliable, packets are tx-ed in sequence and rx-ed in a Best Effort approach
 - **Packet based**
    - Using UDP datagrams as base
 - **64 bit sequence number space (same as QUIC)**
    - 16 byte sequence number in the packet data
    - 64 byte sequence number space
    - increasing only, reaching the end its a connection close condition
 - **Integrity validation via UDP checksum**
    - The UDP checksum field is used to check the integrity of the packets
 - **Minimal security**
    - Duplicate packets are dropped
    - Packets are ordered

### Lacks:
 - No tx/rx rate limiting
 - No retransmission
 - No congestion control

## Best Effort
 - All packets have a unique, increasing only, sequence number
 - The tx will keep track of the last sent sequence number and increment it as it sends packets
 - The rx will keep track of the next accepted sequence number

#### Rx algorithm steps
 - [For every valid received packet]
    1. Compare PacketSequenceNumber to NextAcceptedSequenceNumber
    2. If greater: 
        - NextAcceptedSequenceNumber = PacketSequenceNumber + 1
        - Accept packet
    3. If smaller or equal:
        - Drop packet

## Target platform, tools and libs
|    ~            | Name          | Version               |
|-----------------|---------------|-----------------------|
| <b>Compiler</b> | Clang         | 19+                   |
| <b>OS</b>       | Linux         | 6.1.0-31-amd64 and up |
| <b>Arch</b>     | x86_64        | 64                    |
| <b>Lang</b>     | C++           | 23+                   |
| <b>StdLib</b>   | Clang(libc++) | -                     |
| <b>CMake</b>    | CMake         | 4.0.0 and up          |

## Build
- cmake 
- llvm 19+
- python

<details open>
  <summary><b>Ninja (Recommended)</b></summary>

    mkdir build
    cd build

    # Default
    cmake -G"Ninja" -S ../ -B . -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ 

    # Build
    ninja

</details>
<details>
  <summary><b>Make</b></summary>

    mkdir build
    cd build

    # Default
    cmake -G"Unix Makefiles" -S ../ -B . -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ 

    # Build
    make -j8

</details>

## Features/components/utilities
