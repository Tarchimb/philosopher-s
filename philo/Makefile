SRCS		=	parsing.c							\
				utils.c								\
				simulation.c						\
				
OBJS		=	$(addprefix ${OBJS_DIR}/, ${SRCS:.c=.o})

OBJS_DIR	=	objects
SRCS_DIR	=	srcs

INCLUDES	=	./includes/philo.h					\
				./libft/includes/libft.h			\

CC			= 	gcc
CFLAGS		= 	-Wall -Wextra -Werror -g #-fsanitize=address

LIBINCLUDES	=	-Iincludes -Ilibft/includes

EXECINCLUDES =	-pthreads

LIBS		=	libft.a								\
				${LIB}								\

LIB			=	libphilo.a						

EXEC		=	philo

RM			=	rm -rf	

MKDIR		=	mkdir -p

all:		libft ${EXEC}

${OBJS_DIR}/%.o: 	${SRCS_DIR}/%.c	${INCLUDES} $(OBJDIRS)
			${MKDIR} $(@D) $(DMPDIR)$(@D)
			${CC} ${CFLAGS} ${LIBINCLUDES} -c $< -o $@

$(LIB):		${OBJS} ${INCLUDES}
			ar rcs ${LIB} ${OBJS}

libft:		${INCLUDES}
			make -C libft

${EXEC}:	${EXEC}.c ${LIBS}
			$(CC) ${CFLAGS} ${LIBINCLUDES} ${EXEC}.c ${EXECINCLUDES} ${LIBS} -o ${EXEC}  

clean:
			${RM} ${OBJS} $(OBJS_DIR)
			make clean -C libft

fclean:		clean
			make fclean -C libft
			${RM} ${LIB} ${EXEC} ${LIBS} ${EXEC}.dSYM

re:			fclean all

.PHONY: 	all clean fclean re libft object