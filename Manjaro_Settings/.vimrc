syntax on
set number
set cursorline
set mouse=a
set autoindent
set tabstop=4
set encoding=utf8
set shiftwidth=4
imap ( ()<left>
imap [ []<left>
imap " ""<left>
imap {<CR> {<CR>}<c-o>O<left><right>

map <F2> :call FormatCode()<CR>
func! FormatCode()
    exec "w"
    if &filetype == 'cpp'
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
