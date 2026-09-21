#!/bin/bash
# Сборка лабораторной работы на macOS/Linux.
#
# Использование:
#   ./build.sh 01_lab          — собрать лабораторную №1
#   ./build.sh 01_lab test     — собрать и запустить тесты
#   ./build.sh sample          — собрать пример
#   ./build.sh 01_lab clean    — пересобрать с нуля
#
# Флаг CMAKE_POLICY_VERSION_MINIMUM нужен потому, что в шаблонах
# указан cmake_minimum_required(VERSION 2.8), а CMake 4.x такие
# проекты без него конфигурировать отказывается.
set -e

DIR="${1:?Укажите директорию, например: ./build.sh 01_lab}"
ACTION="${2:-}"

cd "$(dirname "$0")/$DIR"

if [ "$ACTION" = "clean" ]; then
  rm -rf build
  ACTION=""
fi

cmake -S . -B build \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_POLICY_VERSION_MINIMUM=3.5 > /dev/null

cmake --build build -j"$(sysctl -n hw.ncpu 2>/dev/null || nproc)"

echo ""
echo "Готово. Исполняемые файлы: $DIR/build/bin/"
ls -1 build/bin 2>/dev/null || true

if [ "$ACTION" = "test" ]; then
  echo ""
  TEST_BIN=$(find build/bin -name 'test_*' -type f | head -1)
  if [ -n "$TEST_BIN" ]; then
    "$TEST_BIN"
  else
    echo "Тесты в $DIR не найдены."
  fi
fi
