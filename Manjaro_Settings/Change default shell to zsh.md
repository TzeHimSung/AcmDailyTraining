# Change default shell to zsh

- Install zsh (use your software package manager)
- Change shell 

List all useable shells:

```shell
chsh -l
```

and change shell:

```shell
chsh
```

- Install oh-my-zsh with following steps

Launch this command:

```shell
wget https://github.com/robbyrussell/oh-my-zsh/raw/master/tools/install.sh -O - | sh
```

And copy my personal config:

```shell
https://raw.githubusercontent.com/TzeHimSung/CodeforcesDailyTraining/master/Manjaro_Settings/.zshrc
```

- Install missing tools:

```shell
git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-syntax-highlighting
git clone git://github.com/zsh-users/zsh-autosuggestions $ZSH_CUSTOM/plugins/zsh-autosuggestions
source ~.zshrc
```

Now zsh config process is finished!