#!/bin/bash

# Define the allowed editors and required files
allowed_editors="vi vim emacs"
required_files=("0-bubble_sort.c" "1-insertion_sort_list.c" "2-selection_sort.c" "3-quick_sort.c" "sort.h" "README.md")

# Function to check if a file exists
check_file_exists() {
    if [ ! -f "$1" ]; then
        echo "Error: File $1 not found."
        exit 1
    fi
}

# Function to check if an editor is allowed
check_editor_allowed() {
    if [[ ! "$allowed_editors" =~ "$1" ]]; then
        echo "Error: Editor $1 is not allowed."
        exit 1
    fi
}

# Function to check code style using Betty
check_betty_style() {
    betty_style_output=$(betty-style.pl "$1")
    betty_doc_output=$(betty-doc.pl "$1")

    if [ -n "$betty_style_output" ]; then
        echo "$betty_style_output"
        exit 1
    fi

    if [ -n "$betty_doc_output" ]; then
        echo "$betty_doc_output"
        exit 1
    fi
}

# Function to check for forbidden functions
check_forbidden_functions() {
    forbidden_functions=("printf" "puts" "...")  # Add forbidden functions as needed

    for func in "${forbidden_functions[@]}"; do
        if grep -q -w "$func" "$1"; then
            echo "Error: Forbidden function \"$func\" found in $1"
            exit 1
        fi
    done
}

# Main script

# Check required files
for file in "${required_files[@]}"; do
    check_file_exists "$file"
done

# Check editor
if [ -n "$1" ]; then
    check_editor_allowed "$1"
fi

# Check code style
for file in "${required_files[@]}"; do
    check_betty_style "$file"
done

# Check for forbidden functions
for file in "${required_files[@]}"; do
    check_forbidden_functions "$file"
done

# If all checks pass, echo success message
echo "Code passes all checks."
