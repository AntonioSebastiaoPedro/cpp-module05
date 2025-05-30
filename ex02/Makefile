# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/01 20:39:13 by ansebast          #+#    #+#              #
#    Updated: 2025/05/30 09:39:13 by ansebast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Bureaucrat.cpp AForm.cpp main.cpp ShrubberyCreationForm.cpp
HEADERS = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# %.o: %.cpp $(HEADERS)
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re