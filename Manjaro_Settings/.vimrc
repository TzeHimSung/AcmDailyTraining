syntax on
set nocompatible
set backspace=indent,eol,start
set number
set cursorline
set mouse=a
set autoindent
set tabstop=4
set encoding=utf8
set shiftwidth=4
inoremap ( ()<left>
inoremap [ []<left>
inoremap " ""<left>
inoremap ' ''<left>
inoremap {<CR> {<CR>}<c-o>O<left><right><TAB>
inoremap (<CR> (<CR>)<c-o>O<left><right>
inoremap [<CR> [<CR>]<c-o>O<left><right>

map <F2> :call FormatCode()<CR>
func! FormatCode()
    exec "w"
    if &filetype == 'cpp' || &filetype == 'java' || &filetype == 'kt'
        exec "!astyle --options=$HOME/.astylerc %"
        return
    endif
endfunc

map <F5> :call BuildAndRun()<CR>
func! BuildAndRun()
    exec "w"
    if &filetype == 'cpp'
        exec "!g++ -g % -o %<.out -std=c++14 -O2 -Wall"
        exec "! ./%<.out"
    endif
endfunc

map <F9> :call TestProblem()<CR>
func! TestProblem()
	exec "w"
	exec "!cf test"
endfunc

map <F10> :call SubmitProblem()<CR>
func! SubmitProblem()
	exec "w"
	exec "!cf submit"
endfunc

let g:ycm_global_ycm_extra_conf='~/.ycm_extra_conf.py'

autocmd BufNewFile *.cpp 0r ~/Code/DailyTraining/standard.cpp
