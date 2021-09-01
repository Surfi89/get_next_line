/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajordan- <ajordan-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 10:12:58 by ajordan-          #+#    #+#             */
/*   Updated: 2021/09/01 11:57:49 by ajordan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

// strchr busca un caracter (c) dentro de una string (*s)
// En nuestro caso *s es left_str y c es el salto de linea '\n'.

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')                 //Si c es el final del archivo
		return (&s[ft_strlen(s)]); //devolvemos el valor que hay en la ultima posicion de la cadena s
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0'; //Nos protegemos ante la posibilidad de no tener un valor en left_str
	}
	if (!left_str || !buff)
		return (NULL);
	//Reservamos con malloc el tamaño de la nueva string en la que sumaremos left_str y el buffer
	//y le añadimos 1 para añadir el '\0'
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1; //Le ponemos el valor -1 para acortar codigo. Y en el proximo while empezaremos sumando para ponerlo a 0.
	j = 0;  //esto pasa porque si ponemos 0 y luego en el while sumamos nos pasamos de lineas.
	if (left_str)
		while (left_str[++i] != '\0') //Empezamos con ++ para poner i en 0
			str[i] = left_str[i]; //guardamos el contenido de left_str en str
	while (buff[j] != '\0')
		str[i++] = buff[j++]; //guardamos el contenido del buffer en str
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0'; //ponemos el final de la cadena en la posicion final de sumar ambas cadenas.
	free(left_str); //liberamos la memoria reservada con malloc para left_str.
	return (str); //devolvemos la suma de las cadenas con su final.
}

char	*ft_line(char *left_str) //funcion con la que devolveremos la linea con su salto de linea y final.
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2)); //Reservamos para dos huecos mas donde iran el salto de linea y el final.
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n') //copiamos la string left_str en str hasta el primer salto de linea (sin incluir).
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n') //si coincide que habia un '\n' en la original añadimos el salto de linea en esta posicion y avanzamos
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0'; //añadimos el final
	return (str);
}

char	*ft_new_left_str(char *left_str) //funcion con la que guardaremos lo que nos falta por devolver sin lo que hemos devuelto
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n') //avanzamos hasta el proximo salto de linea
		i++;
	if (!left_str[i]) //si no hay nada, liberamos la memoria y devolvemos null
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1)); //reservamos para toda la string de left_str restando lo que
	if (!str)                                                         //habiamos avanzado hasta el salto de linea + el final
		return (NULL);
	i++; //avanzamos a la siguiente posicion tras el salto de linea
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++]; //copiamos lo que hay tras el salto de linea de left_str en str
	str[j] = '\0'; //ponemos el final a la string a devolver
	free(left_str); //liberamos la memoria reservada con el malloc
	return (str); //almacenamos en left_str lo que nos queda por devolver sin lo que hemos devuelto.
}
