#!/bin/bash
rootpasswd=Vu6cVVbI5v

SERVERIP=82.165.163.56
# don't add / at the end
ROOTDIR=/var/www/html/e3-obfuscation-wars/website/laravel
GITHUBURL=https://github.com/woswos/e3-obfuscation-wars

MAINDB=obw
# create random password
#PASSWDDB="$(openssl rand -base64 12)"
PASSWDDB=eFguxkQKKobpXPfv
PORTDB=3306

echo "\n \n"

echo "################################################################"
echo "Updating packages"
echo "################################################################"
sudo apt update -y
sudo apt upgrade -y

echo "\n \n"

echo "################################################################"
echo "Installing apache"
echo "################################################################"
pkgs='apache2'
if ! dpkg -s $pkgs >/dev/null 2>&1; then
	sudo apt install $pkgs -y
	sudo ufw allow “Apache Full”
	sudo systemctl status apache2
else
	echo "Already installed"
fi

echo "\n \n"

echo "################################################################"
echo "Installing php"
echo "################################################################"
pkgs='php libapache2-mod-php php-mbstring php-xmlrpc php-soap php-gd php-xml php-cli php-zip php-bcmath php-tokenizer php-json php-pear php-mysql'
if ! dpkg -s $pkgs >/dev/null 2>&1; then
	sudo apt install $pkgs -y
else
	echo "Already installed"
fi

echo "\n \n"

echo "################################################################"
echo "Installing mariadb server"
echo "################################################################"
pkgs='mariadb-server'
if ! dpkg -s $pkgs >/dev/null 2>&1; then
	sudo apt install $pkgs -y
#	sudo mysql_secure_installation
else
	echo "Already installed"
fi


echo "\n \n"

echo "################################################################"
echo "Installing composer"
echo "################################################################"
pkgs='composer'
if ! dpkg -s $pkgs >/dev/null 2>&1; then
	sudo apt install $pkgs -y
else
       echo "Already installed"
fi

echo "\n \n"

echo "################################################################"
echo "Installing git"
echo "################################################################"
pkgs='git'
if ! dpkg -s $pkgs >/dev/null 2>&1; then
	sudo apt install $pkgs -y
else
       echo "Already installed"
fi

echo "\n \n"

echo "################################################################"
echo "Cloning e3 obw"
echo "################################################################"
if [ ! -d $ROOTDIR ]
then
	sudo apt-get update -y
	cd /var/www/html/
	git clone $GITHUBURL
else
       echo "Already cloned"
fi

echo "\n \n"

echo "################################################################"
echo "Updating composer"
echo "################################################################"
cd $ROOTDIR && composer update && composer install

echo "\n \n"

echo "################################################################"
echo "Creating .env file"
echo "################################################################"
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

echo "################################################################"
echo "Configuring mysql"
echo "################################################################"

mysql -uroot -p${rootpasswd} -e "CREATE DATABASE ${MAINDB} /*\!40100 DEFAULT CHARACTER SET utf8 */;"
mysql -uroot -p${rootpasswd} -e "CREATE USER ${MAINDB}@localhost IDENTIFIED BY '${PASSWDDB}';"
mysql -uroot -p${rootpasswd} -e "GRANT ALL PRIVILEGES ON ${MAINDB}.* TO '${MAINDB}'@'localhost';"
mysql -uroot -p${rootpasswd} -e "FLUSH PRIVILEGES;"

cd $ROOTDIR
php artisan config:cache
php artisan migrate

echo "\n \n"

echo "################################################################"
echo "Linking laravel storage && key generate"
echo "################################################################"
FILE=$ROOTDIR/public/storage
if [ -d $FILE ]
then
   rm -r $FILE
fi

cd $ROOTDIR
php artisan storage:link -v
php artisan key:generate -v

echo "\n \n"

echo "################################################################"
echo "Setting permissions"
echo "################################################################"
sudo chgrp -R www-data $ROOTDIR
sudo chmod -R 775 $ROOTDIR/storage
sudo chown -R www-data:root $ROOTDIR
echo "Done"

echo "\n \n"

echo "################################################################"
echo "Configuring apache"
echo "################################################################"
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
  ErrorLog ${APACHE_LOG_DIR}/error.log
  CustomLog ${APACHE_LOG_DIR}/access.log combined
</VirtualHost>" >> /etc/apache2/sites-available/laravel_project.conf

sudo a2dissite 000-default.conf
sudo a2ensite laravel_project
sudo a2enmod rewrite
sudo systemctl restart apache2
sudo systemctl status apache2

echo "\n \n"

echo "################################################################"
echo "Installing postfix"
echo "################################################################"
pkgs='postfix'
if ! dpkg -s $pkgs >/dev/null 2>&1; then
	echo "postfix postfix/main_mailer_type string 'Internet Site'" | debconf-set-selections
	echo "postfix postfix/mailname string $SERVERIP" | debconf-set-selections
	sudo apt install $pkgs -y
else
        echo "Already installed"
fi

sudo service postfix restart

echo "\n \n"

echo "################################################################"
echo "Installing Dovecot"
echo "################################################################"
pkgs='dovecot-imapd dovecot-pop3d'
if ! dpkg -s $pkgs >/dev/null 2>&1; then
	sudo apt install $pkgs -y
else
        echo "Already installed"
fi

sudo service dovecot restart

echo "\n \n"

echo "################################################################"
echo "Installing unzip"
echo "################################################################"
pkgs='unzip'
if ! dpkg -s $pkgs >/dev/null 2>&1; then
	sudo apt install $pkgs -y
else
        echo "Already installed"
fi

echo "\n \n"

echo "################################################################"
echo "Installing SquirrelMail"
echo "################################################################"
pkgs='SquirrelMail'
if ! dpkg -s $pkgs >/dev/null 2>&1; then
	cd
	wget https://sourceforge.net/projects/squirrelmail/files/stable/1.4.22/squirrelmail-webmail-1.4.22.zip
	unzip squirrelmail-webmail-1.4.22.zip
	sudo mv squirrelmail-webmail-1.4.22 /var/www/html/
	rm squirrelmail-webmail-1.4.22.zip
	sudo chown -R www-data:www-data /var/www/html/squirrelmail-webmail-1.4.22/
	sudo chmod 755 -R /var/www/html/squirrelmail-webmail-1.4.22/
	sudo mv /var/www/html/squirrelmail-webmail-1.4.22/ $ROOTDIR/public/squirrelmail
	sudo rm -rf /var/www/html/squirrelmail-webmail-1.4.22/
	sudo perl $ROOTDIR/public/squirrelmail/config/conf.pl
else
        echo "Already installed"
fi
