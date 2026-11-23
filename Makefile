NAME = libftprintf.a 

SRCS = ft_print.c  ft_print_adrss.c  ft_putchar.c  ft_putnbr.c  ft_putstr.c  ft_to_hexa.c  ft_unsigned_decimal.c 

OBJS = ${SRCS:.c=.o} 

CFLAGS = -Wall -Wextra -Werror

CC =cc

all : ${NAME}

${NAME} : ${OBJS}
		ar rcs  ${NAME} ${OBJS}

%.o :%.c ft_printf.h
		${CC} ${CFLAGS} -c $< -o $@
clean :
		rm -f ${OBJS} 

fclean : clean 
		rm -f ${NAME} 

re : fclean all 

.PHONY : all fclean clean re 
