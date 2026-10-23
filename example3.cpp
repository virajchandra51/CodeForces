// firstSeen[r] = where we first saw remainder r
firstSeen[0] = -1;

long long total = 0;
for (int i = 0; i < n; i++)
{
    total = (total + a[i]) % n;

    if (firstSeen[total] != NOT_SEEN)
        return {firstSeen[total] + 1, i};

    firstSeen[total] = i;
}