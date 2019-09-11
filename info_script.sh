#!/bin/bash

clear
echo -n "Дата :"
date
echo -n "Имя учетной записи: "
whoami
echo -n "Доменное имя ПК: "
hostname
echo "Процессор"
echo -ne "\tМодель:"
lscpu | grep 'Модель' | cut -b 25-
echo -ne "\tАрхитектура:"
lscpu | grep 'Архитектура'| cut -b 30-
echo -ne "\tТактовая частота:"
lscpu | grep 'CPU MHz' | cut -b 19-
echo -ne "\tКоличество ядер:"
lscpu | grep "^CPU(s)" | cut -b 18-
echo -ne "\tКоличество потоков на одно ядро:"
lscpu | grep 'Thread(s) per core' | cut -b 20-
echo "Оперативная память: "
echo -ne "\tВсего: "
free | grep "Mem" | awk '{print $2}'
echo -ne "\tДоступно: "
free | grep "Mem" | awk '{print $4}'
echo "Жесткий диск: "
echo -ne '\tВсего -'
df -hT | grep '/dev/sda1' | awk '{print $3}'
echo -ne '\tДоступно -'
df -hT | grep '/dev/sda1' | awk '{print $5}'
echo -ne '\tСмонтировано в корневую директорию -'
df -h / | sed -n '2p' | awk '{print $1}'
echo -ne '\tSWAP всего-'
swapon | grep 'sda2' | awk '{print $3}'
echo -ne '\tSWAP доступно-'
swapon | grep '/dev/sda2' | awk '{print $3}'
echo -n 'Сетевые интерфейсы - '
echo -ne '\n\tКоличество сетевых интерфейсов - '
ifconfig -s | tail -n3 |  wc -l
echo -e "№\t | Имя сетевого интерфейса\t|\t\tMAC адрес\t|\tIP адрес\t\t| Скорость соединения
echo -ne '1\t\t'
ifconfig | grep "nameofinterface" | tr ':' ' ' | awk '{printf "%s", $1}'
echo -ne '\t\t\t'
ifconfig | grep "nameofinterface" -A 5 | grep "ether" | awk '{printf "%s", $2}'
echo -ne '\t\t'
ifconfig | grep "nameofinterface" -A 5 | grep "inet" | awk '{printf "%s", $2}'
echo -e '\t\t\t1Gbit/s'
echo -ne '2\t\t'
ifconfig | grep "nameofinterface2" | tr ':' ' ' | awk '{printf "%s", $1}'
echo -ne '\t\t\t\t\t'
ifconfig | grep "nameofinterface2" -A 5 | grep "ether" | awk '{printf "%s", $2}'
echo -ne '\t\t' 
ifconfig | grep "nameofinterface2" -A 5 | grep "inet" | awk '{print $2}'
echo -ne '3\t\t'
ifconfig | grep "nameofinterface3" | tr ':' ' ' | awk '{printf "%s", $1}'
echo -ne '\t\t\t\t\t\t'
ifconfig | grep "nameofinterface3" -A 5 | grep "ether" | awk '{printf "%s", $2}'
echo -ne '\t\t\t\t\t\t\t1Gbits/s'
