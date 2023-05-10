/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:56:09 by jduval            #+#    #+#             */
/*   Updated: 2023/04/24 13:18:19 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"

SUITE(test_valid_quotes);
SUITE(test_first_character);
SUITE(test_is_character_spe);
SUITE(test_pass_whitespace);
SUITE(test_valid_redirection);
SUITE(test_redirection_case);
SUITE(test_pipe_case);
SUITE(test_syntax_is_valid);
SUITE(test_normal_word_lengh);
SUITE(test_nbrs_of_pipe);
SUITE(test_find_index_pipe);
SUITE(test_isolate_by_pipe);
SUITE(test_find_rafter);
SUITE(test_rafter_index);
SUITE(test_rafter_id);
SUITE(test_count_words);
SUITE(test_pass_next_word);
SUITE(test_fill_array_cmd);

SUITE(test_split_countwords);
SUITE(test_split_findword);
SUITE(test_split_comparedelim);
SUITE(test_split_endword);
SUITE(test_split);

SUITE(test_exp_nextword);
SUITE(test_exp_dollarvariable);
SUITE(test_node_expand);
SUITE(test_lstexpand);

/*-------TEST_LINKED_LST---------*/
SUITE(test_create_node_redirect);
SUITE(test_put_redirection);

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();	/*	command line initialization. */

	/* Test can also be gathered into test suites. */
	RUN_SUITE(test_valid_quotes);
	RUN_SUITE(test_first_character);
	RUN_SUITE(test_is_character_spe);
	RUN_SUITE(test_pass_whitespace);
	RUN_SUITE(test_valid_redirection);
	RUN_SUITE(test_redirection_case);
	RUN_SUITE(test_pipe_case);
	RUN_SUITE(test_syntax_is_valid);
	RUN_SUITE(test_normal_word_lengh);
	RUN_SUITE(test_nbrs_of_pipe);
	RUN_SUITE(test_find_index_pipe);
	RUN_SUITE(test_isolate_by_pipe);
	RUN_SUITE(test_find_rafter);
	RUN_SUITE(test_rafter_index);
	RUN_SUITE(test_rafter_id);
	RUN_SUITE(test_create_node_redirect);
	RUN_SUITE(test_put_redirection);
	RUN_SUITE(test_pass_next_word);
	RUN_SUITE(test_fill_array_cmd);

	RUN_SUITE(test_split_comparedelim);
	RUN_SUITE(test_split_countwords);
	RUN_SUITE(test_split_findword);
	RUN_SUITE(test_split_endword);
	RUN_SUITE(test_split);

	RUN_SUITE(test_exp_nextword);
	RUN_SUITE(test_exp_dollarvariable);
	RUN_SUITE(test_node_expand);
	RUN_SUITE(test_lstexpand);

	GREATEST_MAIN_END();	/* display result */
}
