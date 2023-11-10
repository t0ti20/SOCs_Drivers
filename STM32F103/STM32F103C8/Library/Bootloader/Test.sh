#!/bin/bash

# Function to reverse bits of a 32-bit word
reverse_bits_32() {
    local value="$1"
    local reversed=0
    for i in {0..31}; do
        reversed=$(( (reversed << 1) | (value & 1) ))
        value=$((value >> 1))
    done
    printf "%08x" $reversed
}

# Function to compute CRC32
compute_crc32() {
    local hexdata="$1"
    # Use Python to compute the CRC32
    python3 -c "
import zlib
data = bytes.fromhex('$hexdata')
crc = zlib.crc32(data) & 0xFFFFFFFF
print('0x{:08X}'.format(crc))
    "
}

# Convert '0x01' to 32-bit little-endian word '0x01000000', reverse its bits, and then compute the CRC32
word_data="01000000"
reversed_data=$(reverse_bits_32 "0x$word_data")
crc_value=$(compute_crc32 "$reversed_data")

echo "CRC-32 for STM32-like processing of '0x01': $crc_value"
