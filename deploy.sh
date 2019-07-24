#!/bin/bash
rootpasswd=1138

SERVERIP=82.165.163.56
# don't add / at the end
ROOTDIR=/var/www/html/e3-obfuscation-wars/website/laravel
GITHUBURL=https://github.com/woswos/e3-obfuscation-wars
E3GITHUBURL=https://github.com/momalab/e3work

MAINDB=obw
# create random password
#PASSWDDB="$(openssl rand -base64 12)"
PASSWDDB=eFguxkQKKobpXPfv
PORTDB=3306

echo "*************************"
echo "INSTALLING WEBSITE"
echo "*************************"

echo "\n"

echo "#########################"
echo "Updating packages"
echo "#########################"
sudo apt update -y
sudo apt upgrade -y

echo "\n \n"

echo "#########################"
echo "Installing apache"
echo "#########################"
pkgs='apache2'
if ! dpkg -s $pkgs >/dev/null 2>&1; then
	sudo apt install $pkgs -y
	sudo ufw allow “Apache Full”
	sudo systemctl status apache2
else
	echo "Already installed"
fi

echo "\n \n"

echo "#########################"
echo "Installing php"
echo "#########################"
pkgs='php libapache2-mod-php php-mbstring php-xmlrpc php-soap php-gd php-xml php-cli php-zip php-bcmath php-tokenizer php-json php-pear php-mysql'
if ! dpkg -s $pkgs >/dev/null 2>&1; then
	sudo apt install $pkgs -y
else
	echo "Already installed"
fi

echo "\n \n"

echo "#########################"
echo "Installing mariadb server"
echo "#########################"
pkgs='mariadb-server'
if ! dpkg -s $pkgs >/dev/null 2>&1; then
	sudo apt install $pkgs -y
#	sudo mysql_secure_installation
else
	echo "Already installed"
fi


echo "\n \n"

echo "#########################"
echo "Installing composer"
echo "#########################"
pkgs='composer'
if ! dpkg -s $pkgs >/dev/null 2>&1; then
	sudo apt install $pkgs -y
else
    echo "Already installed"
fi

echo "\n \n"

echo "#########################"
echo "Installing git"
echo "#########################"
pkgs='git'
if ! dpkg -s $pkgs >/dev/null 2>&1; then
	sudo apt install $pkgs -y
else
    echo "Already installed"
fi

echo "\n \n"

echo "#########################"
echo "Cloning e3 obw"
echo "#########################"
if [ ! -d $ROOTDIR ]
then
	cd /var/www/html/
	git clone $GITHUBURL
else
    echo "Already cloned"
fi

echo "\n \n"

echo "#########################"
echo "Updating composer"
echo "#########################"
cd $ROOTDIR && composer update && composer install

echo "\n \n"

echo "#########################"
echo "Creating .env file"
echo "#########################"
FILE=$ROOTDIR/.env
if test -f "$FILE"; then
   rm $FILE
fi

touch $ROOTDIR/.env
echo "APP_NAME='Obfuscation Wars'
APP_ENV=local
APP_KEY=base64:6/nX95HADVt6ITf6naM/oq8UG73OkEEyGPWoPObUZUY=
APP_DEBUG=true

DB_CONNECTION=mysql
DB_HOST=localhost
DB_PORT=${PORTDB}
DB_DATABASE=${MAINDB}
DB_USERNAME=${MAINDB}
DB_PASSWORD=${PASSWDDB}

MAIL_DRIVER=smtp
MAIL_HOST=obw.barkin.io
MAIL_PORT=465
MAIL_USERNAME=support@obw.barkin.io
MAIL_PASSWORD=KBvqh4rys?Z0
MAIL_ENCRYPTION=ssl
MAIL_FROM_NAME='Obfuscation Wars'
MAIL_FROM_ADDRESS=support@obw.barkin.io" >> $ROOTDIR/.env
echo "Created .env file and added contents"

echo "\n \n"

echo "#########################"
echo "Configuring mysql"
echo "#########################"

mysql -uroot -p${rootpasswd} -e "CREATE DATABASE ${MAINDB} /*\!40100 DEFAULT CHARACTER SET utf8 */;"
mysql -uroot -p${rootpasswd} -e "CREATE USER ${MAINDB}@localhost IDENTIFIED BY '${PASSWDDB}';"
mysql -uroot -p${rootpasswd} -e "GRANT ALL PRIVILEGES ON ${MAINDB}.* TO '${MAINDB}'@'localhost';"
mysql -uroot -p${rootpasswd} -e "FLUSH PRIVILEGES;"

cd $ROOTDIR
php artisan config:cache
php artisan migrate

echo "\n \n"

echo "#########################"
echo "Linking laravel storage && key generate"
echo "#########################"
FILE=$ROOTDIR/public/storage
if [ -d $FILE ]
then
   rm -r $FILE
fi

cd $ROOTDIR
php artisan storage:link -v
php artisan key:generate -v

echo "\n \n"

echo "#########################"
echo "Setting permissions"
echo "#########################"
sudo chgrp -R www-data $ROOTDIR
sudo chmod -R 775 $ROOTDIR/storage
sudo chown -R www-data:root $ROOTDIR
echo "Done"

echo "\n \n"

echo "#########################"
echo "Configuring apache"
echo "#########################"
FILE=/etc/apache2/sites-available/laravel_project.conf
if test -f "$FILE"; then
   rm $FILE
fi

touch /etc/apache2/sites-available/laravel_project.conf
echo "<VirtualHost *:80>
  ServerName $SERVERIP
  ServerAdmin webmaster@82.165.163.56
  DocumentRoot $ROOTDIR/public

  <Directory $ROOTDIR>
      AllowOverride All
  </Directory>

  <Directory $ROOTDIR/public/roundcube/>
	 Options FollowSymlinks
	 AllowOverride All
	 Require all granted
  </Directory>

  ErrorLog ${APACHE_LOG_DIR}/error.log
  CustomLog ${APACHE_LOG_DIR}/access.log combined
</VirtualHost>" >> /etc/apache2/sites-available/laravel_project.conf

sudo a2dissite 000-default.conf
sudo a2ensite laravel_project
sudo a2enmod rewrite
sudo systemctl restart apache2
sudo systemctl status apache2

echo "\n \n"

echo "#########################"
echo "Installing unzip"
echo "#########################"
pkgs='unzip'
if ! dpkg -s $pkgs >/dev/null 2>&1; then
	sudo apt install $pkgs -y
else
    echo "Already installed"
fi

echo "\n \n"

echo "*************************"
echo "INSTALLING BENCHMARKS"
echo "*************************"

echo "\n"

echo "#########################"
echo "Installing python3"
echo "#########################"
pkgs='python3'
if ! dpkg -s $pkgs >/dev/null 2>&1; then
	sudo apt install $pkgs -y
else
	echo "Already installed"
fi

sudo apt install python3-pip
pip3 install --upgrade setuptools
pip3 install mysql-connector-python

echo "\n \n"

echo "#########################"
echo "Installing make, gcc, cpp"
echo "#########################"
pkgs='make'
if ! dpkg -s $pkgs >/dev/null 2>&1; then
	sudo apt-get install build-essential -y
else
	echo "Already installed"
fi

echo "\n \n"

echo "#########################"
echo "Cloning e3"
echo "#########################"
if [ ! -d /root/e3work ]
then
	cd /root
	git clone $E3GITHUBURL
else
    echo "Already cloned"
fi

echo "\n \n"

echo "#########################"
echo "Building e3"
echo "#########################"
cd /root/e3work/src && make && make check
