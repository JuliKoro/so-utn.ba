# B-Consigna y programa para analizar so_padre/so_hijo



Analice y verifique los dos archivos adjuntados. Para compilarlos utilice los comandos siguientes:

gcc so_padre.c -o so_padre

gcc so_hijo.c -o so_hijo

Es importante que los ejecutables estén en la misma carpeta y tengan los nombres sugeridos en los comandos para compilar.

Verifique y compruebe la funcionalidad de so_hijo (es muy simple).

Luego ejecute so_padre usando el comando ./so_padre todas las veces que sea necesario para analizar los procesos utilizando ps. Una vez con ps abierto concéntrese en el procesos llamados so_padre y so_hijo.

Use dos consolas simultáneas, una para ejecutar ps (visor de procesos) y otra para ejecutar so_padre

Ejecute ps de la siguiente manera:

watch -n 1 'ps -efo pid,ppid,stat,pmem,rss,vsz,comm | grep -E '\''so_|COMMAND'\'''

watch hace que la salida de ps se refresque cada un segundos de manera constante, lo que permitirá controlar el comportamiento de los procesos de manera tal que filtre las líneas de encabezado y los procesos con nos interesan. Ps tendrá las siguientes columnas por cada proceso:

PID: ID del proceso

PPID: ID del proceso padre

STAT: Estado del proceso

RSS + VSZ: La suma de la memoria ocupada por el proceso (expresada en Kilobytes).

COMMAND: el nombre del proceso que ejecuta

Usando el comando "man ps", puede buscar el significado de los diferentes estados que toman los procesos.

Analice cómo varían los procesos a medida que se ejecuta so_padre y responda el cuestionario que encontrará en la sección de Procesos.
