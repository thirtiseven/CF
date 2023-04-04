def mountain_climber_pattern(s: str) -> str:
    vowel = False
    
    for i, c in enumerate(s):
        if c.lower() in 'aeiou':
            if not vowel:
                return 'NO'
            vowel = False
        else:
            if vowel:
                return 'NO'
            vowel = True
            
    return 'YES'

# Test the function
test_string = 'bocchiryonijikakitasingingsongs'
print(mountain_climber_pattern(test_string))