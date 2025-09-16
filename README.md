# Динамическая память и реализация динамического массива в C
**Автор:** Vladislav Moroz <morozvv75@gmail.com>

## Описание
Лабораторная работа посвящена изучению динамического выделения памяти в языке C и созданию собственной реализации динамического массива (`vector`).  
В работе реализованы основные операции:
- Добавление и удаление элементов
- Вставка и удаление по индексу
- Автоматическое расширение массива
- Получение размера и печать элементов

## Используемые технологии
- Язык: C
- Компилятор: gcc
- Asciidoctor PDF для генерации документации
- Библиотеки: стандартная библиотека C (`stdlib.h`, `stdio.h`)

## Структура проекта
- `lab.adoc` — исходный файл с документацией и кодом
- `vector.c` — реализация динамического массива

Генерация PDF документации

Установка необходимого софта
```
#Ubuntu/Debian
sudo apt update
sudo apt install -y \
  ruby \
  ruby-dev \
  build-essential \
  zlib1g-dev \
  asciidoctor \
  libasciidoctor-pdf-ruby \
  fonts-dejavu fonts-noto-cjk fonts-noto-color-emoji

#Fedora
sudo dnf install -y \
  ruby \
  ruby-devel \
  gcc \
  make \
  redhat-rpm-config \
  rubygem-asciidoctor \
  rubygem-asciidoctor-pdf \
  google-noto-sans-cjk-fonts \
  google-noto-emoji-fonts

```
сборка проекта

```
asciidoctor-pdf lab.adoc
```