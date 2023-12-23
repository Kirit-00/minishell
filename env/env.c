#include "../minishell.h"

int strlen1(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}
// carleni = karakterini bulumu için kullanıyorum :)
int carlen(char *str, char c)
{
	int i;

	i = 0;
	while(str[i] && str[i] != c)
		i++;
	return (i);
}

//str and strstr fonskiyonunda actıgımız iki stringden ilkini env ın = önceki kısmını orada doldurmustuk
// Burada = den sonraki kısmı 2 boyutlu stringimin icindeki 2. stringime dolduruyorum.
void env_and_str2(char *env,char **string, int i)
{
	int j;

	j = 0;
	if(env[i] == '=' && env[i + 1] == '\0')
		string[1][0] = '\0';
	else if(env[i] == '\0')
	{
		free(string[1]);
		string[1] = NULL;
	}
	else
	{
		while (env[++i] != '\0') 
			string[1][j++] = env[i];
		string[1][j] = '\0';
	}
}
// envları bolmek icin için 2 boyutlu bir string oluşturdum.Stringime yer actım daha sonra =
// görene kadar carlene saydırdım ilk stringime yer actım. Daha sonra bütün stringi saydırıp ilk stringin 
// uzunlugundan cıkarak yer actım. ve ilk stringimin içini = koyana kadar doldurdum :D
// devam ke mk :)=
char **env_and_str1(char *env)
{
	char **string;
	int i;

	i = carlen(env, '=');
	string =(char **)malloc(sizeof(char **) * 2);
	string[0] = malloc(sizeof(char) *  (i + 1));
	i = (strlen1(env) -  i);
	string[1] = malloc(sizeof(char) * ( i + 1));
	i = 0;
	while(env[i] && env[i] != '=')
	{
		string[0][i] = env[i];
		i++;
	}
	string[0][i] = '\0';
	env_and_str2(env, string, i);
	return(string);
}

void ft_init_env(t_env **env1, char **env)
{
	t_env	*new;
	char	**str;
	int		i;

	new = NULL;
	i = 0;
	while (env[i])
	{
		str =env_and_str1(env[i]);
		new = ft_create_env_node(str[0], str[1]);
		ft_add_list(env1, new);
		free(str[0]);
		free(str[1]);
		free(str);
		i++;
	}
}