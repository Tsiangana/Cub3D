# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pzau <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 14:59:58 by pzau              #+#    #+#              #
#    Updated: 2025/03/17 15:00:34 by pzau             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = cub3d
MANDATORY_DIR = mandatory
BONUS_DIR = bonus

all:
	$(MAKE) -C $(MANDATORY_DIR)
	mv $(MANDATORY_DIR)/$(EXEC) .

bonus:
	$(MAKE) -C $(BONUS_DIR)
	mv $(BONUS_DIR)/$(EXEC) .

clean:
	$(MAKE) -C $(MANDATORY_DIR) clean

cleanb:
	$(MAKE) -C $(BONUS_DIR) clean

fclean:
	$(MAKE) -C $(MANDATORY_DIR) fclean
	rm -f $(EXEC)

fcleanb:
	$(MAKE) -C $(BONUS_DIR) fclean
	rm -f $(EXEC)

re: fclean all

reb: fcleanb bonus

.PHONY: all bonus clean cleanb fclean fcleanb re reb

