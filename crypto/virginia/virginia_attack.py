#! /usr/bin/env python
# coding: utf-8
print
path = raw_input('Please input ciphertext file path: ')
#f = open('f:/abc_ciphertext.txt', 'r')
print
f = open(path, 'r')
f_text = f.readline()
f.close()
# print f_text

charset = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
           'u', 'v', 'w', 'x', 'y', 'z']
frequencyset = [0.0805, 0.0162, 0.0320, 0.0365, 0.1231, 0.0228, 0.0161, 0.0514, 0.0718, 0.0010, 0.0052, 0.0403, 0.0225,
                0.0719, 0.0794, 0.0229, 0.0020, 0.0603, 0.0659, 0.0959, 0.0310, 0.0093, 0.0203, 0.0020, 0.0188, 0.0009]
ic = []
len_key = 0
# len(f_text) + 1

for i in range(2, 10):#讲密文分成2，3，4，... len(f_text)个字串，分别去求平均IC
    ic_secton = []
    for j in range(i):#求每个子串的IC
        section = f_text[j::i]
        sum_section = len(section)
        ic_chara = []
        for k in charset:#在子串中求每个字符的IC
            sum_chara = section.count(k)
            ic_chara.append(float(sum_chara*(sum_chara-1)) / float(sum_section*(sum_section-1)))
        tmp = 0
        for l in ic_chara:#将每个字符的IC相加就是子串的IC
            tmp += l
        ic_secton.append(tmp)
    tmp = 0
    for m in ic_secton:#求各个字串IC相加求平均值即为最终IC
        tmp += m
    ic.append(tmp / i)
# print ic
for i in ic:#获取key的长度
    if 0.060 <= i <= 0.070:
        len_key = ic.index(i) + 2
        break
print 'Length of key:', len_key
# len_key =  ic.index(max(ic)) + 2
# print 'Length of key:', len_key

key_set = []
key = ''
for i in range(len_key):#获取密钥的编码集合key_set
    section = f_text[i::len_key]
    sum_section = len(section)
    m_section = []
    for k in range(26):
        m_chara = []
        section_tmp = ''
        for l in section:
            for m in charset:
                if l == m:
                    l = charset[charset.index(m) - k]
                    break
            section_tmp += l
        for j in charset:
            sum_chara = section_tmp.count(j)
            m_chara.append(frequencyset[charset.index(j)] * float(sum_chara) / float(sum_section))
        sum_m_chara = 0
        for n in m_chara:
            sum_m_chara += n
        m_section.append(sum_m_chara)
    key_set.append(m_section.index(max(m_section)))

# print key_set
for o in key_set:#由密钥的编码获取key
    key += charset[o]

print 'Key:', key