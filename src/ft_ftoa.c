/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:20:43 by cjosue            #+#    #+#             */
/*   Updated: 2019/10/19 16:22:22 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void reverse(char s[])
{
    int i, j;
    char c;
    
    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(long int n, char s[])
{
    long int i, sign;
    
    if ((sign = n) < 0)  
        n = -n;          
    i = 0;
    do {      
        s[i++] = n % 10 + '0';   
    } while ((n /= 10) > 0);    
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void    ft_print_float(float f)
{
    unsigned int    i;
    int                index;
    
    i = 0;
    index = 31;
    memcpy(&i, &f, sizeof(float));
    while (index >= 0)
    {
        if (index == 30 || index == 22)
            write(1, ".", 1);
        if (i & (1U << index))
            write(1, "1", 1);
        else
            write(1, "0", 1);
        index--;
    }
    write(1, "\n", 1);
}

char        *ft_ftoa_mod(float num, long int *num_mod)
{
    int        tmp_num;
    int        exp;
    int        index;
    char    *arr;
    
    index = 30;
    *num_mod = 1L;
    exp = 0;
    memcpy(&tmp_num, &num, sizeof(float));
    arr = ft_strnew(20);
    while (index > 22)
    {
        exp <<= 1;
        if (tmp_num & 1U << index)
            exp |= 1U;
        index--;
    }
    exp -= 127;
    while (exp > 0 && index >= 0)
    {
        if (index < 0)
            index = 22;
        *num_mod <<= 1;
        if(tmp_num & 1U << index)
            *num_mod |= 1L;
        index--;
        exp--;
    }
    while (exp > 0)
    {
        *num_mod <<= 1;
        exp--;
    }
    itoa(*num_mod, arr);
    return (arr);
}

char    *ft_ftoa_div(float num, int pr)
{
    char    *arr_div;
    int        i;
    long int    tmp;
    long int
    
    i = 0;
    arr_div = ft_strnew(1);
    pr += 1;
    tmp = 0;
    while (i < pr)
    {
        printf("%.10f __num\n", num);
        num *= 2.00;
        if (num < 1.00)
            arr_div[i] = '0';
        else
        {
            arr_div = ft_strjoin(arr_div, ft_ftoa_mod(num, &tmp));
            num = num - tmp;
        }
        i++;
    }
    i -= 1;
    if (arr_div[i] > '5')
        arr_div[i - 1]++;
    arr_div[i] = '\0';
    return (arr_div);
}

char    *ft_ftoa(float num, int pr)
{
    long int    num_mod;
    char        *arr_mod;
    char        *arr_div;
    
    arr_mod = ft_strnew(2);
    if (num < 0)
    {
        num *= (-1.00);
        arr_mod = ft_strjoin(arr_mod, "-");
    }
    if (num < 1)
    {
        arr_mod = ft_strjoin(arr_mod, "0.");
        arr_mod = ft_strjoin(arr_mod, ft_ftoa_div(num, pr));
        return (arr_mod);
    }
    arr_mod = ft_strjoin(arr_mod, ft_ftoa_mod(num, &num_mod));
    num -= num_mod;
    arr_mod = ft_strjoin(arr_mod, ".");
    arr_mod = ft_strjoin(arr_mod, ft_ftoa_div(num, pr));
    return (arr_mod);
}
