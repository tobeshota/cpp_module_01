#!/bin/bash

# - settings ---------------------------
# 実行ファイル名
readonly EXECUTABLE_FILE_NAME="harl"

# テスト項目を記述するファイル名（未指定の場合，run_test関数記載のテストが実施される）
# ファイルの書式: <実行ファイルの引数> ; <望まれる出力結果>
readonly QA_FILE_NAME="qa.txt"
# --------------------------------------

readonly EXECUTABLE_DIR_PATH=$(dirname "$0")
readonly EXE="${EXECUTABLE_DIR_PATH}/${EXECUTABLE_FILE_NAME}"
readonly QA_DIR_PATH="${EXECUTABLE_DIR_PATH}"
readonly QA="${QA_DIR_PATH}/${QA_FILE_NAME}"
readonly MAKEFILE_PATH="${EXECUTABLE_DIR_PATH}/Makefile"
readonly TEST_NAME="${EXECUTABLE_FILE_NAME} test"
readonly GREEEN="\033[32m"
readonly RED="\033[31m"
readonly DEFAULT="\033[39m"
readonly OK=${GREEEN}OK${DEFAULT}
readonly KO=${RED}KO${DEFAULT}

g_test_cnt=0;
g_test_passed=0;
g_test_failed=0;

function err
{
  echo $* >&2
}

# - init ---------------------------
function init
{
  printf "\ \ \ \ \ \ \ \ \ \ ${TEST_NAME} / / / / / / / / / /\n"
  if ! build; then
    err "failed to build"
    exit 1
  fi
}

# - build ---------------------------
function build
{
  printf "|- - - - - - - - - - build - - - - - - - - - -|\n"
  make -f ${MAKEFILE_PATH} || return 1
  return 0
}

# - results ---------------------------
function print_result
{
  printf "\n|- - - - - - - - - - results - - - - - - - - - -|\n"
  printf "${g_test_cnt} tests run\n"
  printf "${GREEEN}${g_test_passed}${DEFAULT} passed\n"
  printf "${RED}${g_test_failed}${DEFAULT} failed\n"
  if [ ${g_test_cnt} -eq ${g_test_passed} ]; then
    printf "${GREEEN}Congratulations!${DEFAULT}\n"
  fi
}

# - assert ---------------------------
function assert_from_qafile
{
  # Q/Aファイルが存在するかチェック
  if [ ! -e "$QA" ]; then
    echo "file not found: $QA"
    exit 1
  fi

  # ファイルから1行を読み取る
  while IFS= read -r line; do
    # セミコロンを区切り文字として分割
    IFS=';' read -r test_param expect <<< "$line"

    # ダブルクォートをトリム
    test_param=$(echo $test_param | sed 's/^ *"//;s/" *$//')
    expect=$(echo $expect | sed 's/^ *"//;s/" *$//')
    assert "$(${EXE} ${test_param} 2>&1)" "${expect}"
  done < "$QA"
}

function assert
{
  local actual=$1
  local expect=$2

  printf "${g_test_cnt}."
  if [ "${actual}" == "${expect}" ]; then
    printf "${OK} "
    ((g_test_passed++))
  else
    printf "${KO}\n"
    echo "expected: [${expect}]"
    echo "actual  : [${actual}]"
    ((g_test_failed++))
  fi
    ((g_test_cnt++))
}

# - run_test ---------------------------
function run_test
{
  printf "|- - - - - - - - - - start - - - - - - - - - -|\n"
  # Q/Aファイルが存在するかチェック
  if [ -e "$QA" ]; then
    assert_from_qafile
  else
    # Q/Aファイルを用意しない場合，以下の項目をテストする
    # 追加形式: assert <actual> <expect>
    assert "$(${EXE} DEBUG 2>&1)" "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
    assert "$(${EXE} INFO 2>&1)" "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
    assert "$(${EXE} WARNING 2>&1)" "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
    assert "$(${EXE} ERROR 2>&1)" "This is unacceptable! I want to speak to the manager now."
    assert "$(${EXE} hoge 2>&1)" "complain supports following level: DEBUG, INFO, WARNING, ERROR"
  fi
}

# - main ---------------------------
function main
{
  init
  run_test
  print_result
  if [ ${g_test_failed} -ne 0 ]; then
    return 1
  fi
  return 0
}

main "$@"
