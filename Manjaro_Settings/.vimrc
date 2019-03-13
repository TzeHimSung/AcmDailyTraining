" All system-wide defaults are set in $VIMRUNTIME/archlinux.vim (usually just
" /usr/share/vim/vimfiles/archlinux.vim) and sourced by the call to :runtime
" you can find below.  If you wish to change any of those settings, you should
" do it in this file (/etc/vimrc), since archlinux.vim will be overwritten
" everytime an upgrade of the vim packages is performed.  It is recommended to
" make changes after sourcing archlinux.vim since it alters the value of the
" 'compatible' option.

" This line should not be removed as it ensures that various options are
" properly set to work with the Vim-related packages.
runtime! archlinux.vim

" If you prefer the old-style vim functionalty, add 'runtime! vimrc_example.vim'
" Or better yet, read /usr/share/vim/vim80/vimrc_example.vim or the vim manual
" and configure vim to your own liking!

" do not load defaults if ~/.vimrc is missing
"let skip_defaults_vim=1

syntax on
set nu
set tabstop=4
set shiftwidth=4
set smarttab
set cindent
set nobackup
set noswapfile
set mouse=a
"colo evening

map <F6> :call CR()<CR>
func! CR()
exec "w"
exec "!g++ % -o %<"
exec "! ./%<"
endfunc

imap <c-]> {<cr>}<c-o>O<left><right>
map <F2> :call SetTitle()<CR>
func SetTitle()
let l=0
let l=l+1 | call setline(l,'#include <bits/stdc++.h>')
let l=l+1 | call setline(l,'')
let l=l+1 | call setline(l,'using namespace std;')
let l=l+1 | call setline(l,'')
let l=l+1 | call setline(l,'int main()')
let l=l+1 | call setline(l,'{')
let l=l+1 | call setline(l,'    ')
let l=l+1 | call setline(l,'    return 0;')
let l=l+1 | call setline(l,'}')
endfunc
