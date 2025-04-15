#!/bin/bash

echo "📦 Removing all Visual Studio files from Git tracking (not from disk)..."

# Remove tracked VS-related files/folders
git rm -r --cached $(find . \
  -type d -name .vs -o \
  -type d -name x64 -o \
  -type f -name "*.sln" -o \
  -type f -name "*.vcxproj" -o \
  -type f -name "*.vcxproj.filters" -o \
  -type f -name "*.vcxproj.user")

echo "✅ Removed from Git tracking."

# Make sure .gitignore has the needed patterns
GITIGNORE=".gitignore"
NEEDED_PATTERNS=(
  ".vs/"
  "x64/"
  "*.sln"
  "*.vcxproj"
  "*.vcxproj.filters"
  "*.vcxproj.user"
)

for pattern in "${NEEDED_PATTERNS[@]}"; do
  if ! grep -qxF "$pattern" "$GITIGNORE"; then
    echo "$pattern" >> "$GITIGNORE"
    echo "➕ Added '$pattern' to .gitignore"
  fi
done

# Commit and push
git add .gitignore
git commit -m "Cleanup: Remove Visual Studio files from tracking and update .gitignore"
git push origin main

echo "🚀 Done! Your repo is clean now."
