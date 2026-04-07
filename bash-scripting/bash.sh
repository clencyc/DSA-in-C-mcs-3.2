#!/usr/bin/env bash
set -euo pipefail

# -------------------------------------------------------
# TOPIC 13: Functions
# Reusable helper functions defined at the top
# -------------------------------------------------------

usage() {
    echo "Usage: $0 <file_or_directory>"
    echo "  Checks if a path exists and shows info about it."
    exit 1
}

log() {
    # TOPIC 5: $(...) captures output of 'date' command
    local timestamp
    timestamp=$(date +"%Y-%m-%d %H:%M:%S")
    echo "[LOG $timestamp] $1"
}

error() {
    local timestamp
    timestamp=$(date +"%Y-%m-%d %H:%M:%S")
    echo "[ERROR $timestamp] $1" >&2   # >&2 sends to stderr
}

check_path() {
    local path="$1"

    # TOPIC 6: if [ ] with file tests (-f, -d, -e)
    if [ ! -e "$path" ]; then
        error "Path does not exist: $path"
        return 1        # non-zero exit code = failure
    fi

    if [ -f "$path" ]; then
        log "Regular file detected: $path"

        # TOPIC 5: capture file size and line count using $(...)
        local size line_count
        size=$(wc -c < "$path")
        line_count=$(wc -l < "$path")

        echo "  Size       : $size bytes"
        echo "  Line count : $line_count lines"

    elif [ -d "$path" ]; then
        log "Directory detected: $path"

        # TOPIC 5: capture number of items inside directory
        local item_count
        item_count=$(ls "$path" | wc -l)

        echo "  Items inside: $item_count"
    fi

    return 0    # zero exit code = success
}


# -------------------------------------------------------
# MAIN — argument check + function calls
# -------------------------------------------------------

# TOPIC 6: check argument count, show usage if missing
if [ $# -lt 1 ]; then
    error "No argument provided."
    usage
fi

TARGET="$1"

log "Script started by $(whoami)"   # TOPIC 5: $(...) captures current user

check_path "$TARGET"

# TOPIC 6: $? holds exit code of the last command
if [ $? -eq 0 ]; then
    log "Done. All checks passed."
else
    error "Something went wrong."
    exit 1
fi
