/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajordan- <ajordan-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 10:12:14 by ajordan-          #+#    #+#             */
/*   Updated: 2021/09/01 12:27:52 by ajordan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Esta funcion la usaremos para liberar la memoria reservada en caso de error al leer el archivo.
void	ft_check_read(int rd_bytes, char *buff)
{
	if (rd_bytes == -1)
		free(buff);
}

char	*get_next_line(int fd)
{
	char		*buff; //Reserva de memoria.
	int			rd_bytes; //Numero de bytes leidos con read.
	char		*line; //Linea que vamos a devolver.
	static char	*left_str; //Esta sera la variable estatica donde almacenaremos la informacion que nos queda por devolver
                         //y la iremos actualizando cada vez que lancemos el programa quitando cada vez
                         //la linea que ya hemo devuelto.

// Protegemos ante posibles errores devolviendo NULL
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
//Reservamos con malloc la memoria para el buffer con el tamaño que se ha determinado al lanzar el programa.
//Le añadimos +1 ya que vamos a añadir un salto de linea al final
//Despues protegemos la funcion
	buff = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
//Utilizamos la funcion ft_strchr para encontrar el primer salto de linea dentro del tamaño de buffer determinado.
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
//Leemos el archivo hasta el tamaño determinado y guardamos el numero de bytes leidos con read en la variable rd_bytes.
//Si la lectura falla, liberamos la memoria y devolvemos NULL.
//Si se ha leido correctamente añadimos un final de cadena al buffer hasta el tamaño de bytes que hemos leido.
//Finalmente usamos la funcion strjoin para reservar en left_str la memoria de lo que hemos usado hasta ahora (left_str)
//mas lo que queremos usar (buff).
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		ft_check_read(rd_bytes, buff);
		if (rd_bytes == -1)
			return (NULL);
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff); //liberamos la memoria reservada en buffer.
	line = ft_line(left_str); //buscamos la linea a devolver con ft_line y la guardamos en la variable linea.
	left_str = ft_new_left_str(left_str); //
	return (line);
}

/*int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
*/
