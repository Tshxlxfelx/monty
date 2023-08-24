int is_numeric(const char *str)
{
    if (!str)
        return 0;

    for (const char *c = str; *c != '\0'; ++c)
    {
        if (!isdigit(*c) && *c != '-' && *c != '+')
            return 0;
    }

    return 1;
}

