SRCS		=	parsing.c							\
				utils.c								\
				simulation.c						\
				action.c							\
				time.c								\
				life.c								\
				
OBJS		=	$(addprefix ${OBJS_DIR}/, ${SRCS:.c=.o})

OBJS_DIR	=	objects
SRCS_DIR	=	srcs

INCLUDES	=	./includes/philo.h					\

CC			= 	gcc
CFLAGS		= 	-Wall -Wextra -Werror #-fsanitize=thread

LIBINCLUDES	=	-Iincludes 

EXECINCLUDES =	-pthreads

LIB			=	libphilo.a						

EXEC		=	philo

RM			=	rm -rf	

MKDIR		=	mkdir -p

all:		${EXEC}

${OBJS_DIR}/%.o: 	${SRCS_DIR}/%.c	${INCLUDES} $(OBJDIRS)
			${MKDIR} $(@D)
			${CC} ${CFLAGS} ${LIBINCLUDES} -c $< -o $@

$(LIB):		${OBJS} ${INCLUDES}
			ar rcs ${LIB} ${OBJS}


${EXEC}:	${EXEC}.c ${LIB} Makefile
			$(CC) ${CFLAGS} ${LIBINCLUDES} ${EXEC}.c ${EXECINCLUDES} ${LIB} -o ${EXEC}  

clean:
			${RM} ${OBJS} $(OBJS_DIR)

fclean:		clean
			${RM} ${LIB} ${EXEC} ${LIB} ${EXEC}.dSYM

re:			fclean all

.PHONY: 	all clean fclean re object