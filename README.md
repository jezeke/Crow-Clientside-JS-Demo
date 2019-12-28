### Usage instructions:

See build instructions for Crow in /crow/README.md. For further information about Crow or any issues with it, please visit https://github.com/ipkn/crow. Note that this demo uses HTTP. This can be easily converted to use TLS / HTTPS, see previous link for resources and examples on this.

Install nginx and then see the set-up instructions for nginx in /www/nginx_conf. Note that this service should work fine with routing from any web server (Apache, etc.) however set-up is up to you.

Start nginx and the compiled Crow service, then connect to host server with a web browser and submit an email at the form to see the POST request made to server then returned by the server.

Please submit an issue on Github with a proof of concept if you are able to remotely compromise a host running this service behind an up to date version of nginx (via buffer overflow, etc.).
