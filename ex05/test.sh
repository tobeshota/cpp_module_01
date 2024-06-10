#!/bin/bash

readonly EXECUTABLE_FILE_NAME="harl"
readonly SCRIPT_DIR_PATH=$(dirname "$0")
readonly EXE="${SCRIPT_DIR_PATH}/${EXECUTABLE_FILE_NAME}"
readonly MAKEFILE_PATH="${SCRIPT_DIR_PATH}/Makefile"
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

# init
function init
{
  printf "\ \ \ \ \ \ \ \ \ \ ${TEST_NAME} / / / / / / / / / /\n"
  if ! build; then
    err "failed to build"
    exit 1
  fi
}

function build
{
  printf "|- - - - - - - - - - build - - - - - - - - - -|\n"
  make -f ${MAKEFILE_PATH} || return 1
  return 0
}

function print_result {
  printf "\n|- - - - - - - - - - results - - - - - - - - - -|\n"
  printf "${g_test_cnt} tests run\n"
  printf "${GREEEN}${g_test_passed}${DEFAULT} passed\n"
  printf "${RED}${g_test_failed}${DEFAULT} failed\n"
  if [ ${g_test_cnt} -eq ${g_test_passed} ]; then
    printf "${GREEEN}Congratulations!${DEFAULT}\n"
  fi
}

function assert {
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

function run_test {
  printf "|- - - - - - - - - - start - - - - - - - - - -|\n"

  # 以下にテストを追加
  # 追加形式: assert <actual> <expect>
  assert "$(${EXE} DEBUG)" "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
  assert "$(${EXE} INFO)" "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
  assert "$(${EXE} WARNING)" "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
  assert "$(${EXE} ERROR)" "This is unacceptable! I want to speak to the manager now."
}

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
