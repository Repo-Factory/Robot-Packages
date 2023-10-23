#!/bin/bash

# Get the absolute path of the script's directory
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Set the target directory where the scripts will be copied
TARGET_DIR="/usr/scripts"

# Check if the target directory exists, if not, create it
if [ ! -d "$TARGET_DIR" ]; then
    sudo mkdir -p "$TARGET_DIR"
    sudo chown -R "$(whoami)" "$TARGET_DIR"
fi

# Copy all subdirectories to the target directory
for dir in "$SCRIPT_DIR"/*/; do
    if [ -d "$dir" ]; then
        for script in "$dir"/*; do
            if [ -f "$script" ]; then
                cp "$script" "$TARGET_DIR"
            fi
        done
    fi
done

add_all_directores_to_bash_rc()
{
    # Update the PATH in ~/.bashrc
    echo "Adding directories to PATH in ~/.bashrc"
    for dir in "$TARGET_DIR"/*; do
        if [ -d "$dir" ]; then
            echo "export PATH=\$PATH:$dir" >> ~/.bashrc
        fi
    done
}

# flag to add to bashrc
while [[ $# -gt 0 ]]; do
    case "$1" in
        -a|--add)
           add_all_directores_to_bash_rc;;
    esac
    shift
done

# Refresh the shell configuration
source ~/.bashrc

echo "Setup complete. You can now use the scripts from the new directories."


