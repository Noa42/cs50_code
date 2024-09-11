import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: dna database sequence")
        return 1

    # TODO: Read database file into a variable
    database = []
    with open(sys.argv[1]) as file:
        data_reader = csv.DictReader(file)
        for row in data_reader:
            database.append(row)
    #print(database)
    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2]) as file:
        seq_reader = csv.reader(file)
        sequence_list = list(seq_reader)
    sequence = sequence_list[0][0]
    # TODO: Find longest match of each STR in DNA sequence
    strs = list()
    for key in database[0]:
        if key != 'name':
            strs.append(key)
    #print(strs)
    results = {}
    for str in strs:
        results[str] = longest_match(sequence, str)
    #print(results)
    #print(len(database))
    # TODO: Check database for matching profiles
    i = 0
    match_found = False
    for dict in database:
        #total_match = True
        i = 0
        for str in strs:
            if results[str] == int(dict[str]):
                #total_match = False
                i +=1
                #print(f"Perosna = {dict['name']}, {str}, {results[str]}-{int(dict[str])}, matches{i}")
                continue
        if i == len(strs): #total_match == True and
                print(f"{dict['name']}")
                match_found = True
    if match_found == False:
        print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
