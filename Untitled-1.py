import pandas as pd
import numpy as np

df = pd.read_csv('battery.csv', usecols=['Cycle','Status', 'Voltage(V)', 'CapaCity(mAh)'])

def filter(df):
  temp = df['Voltage(V)'][0]

  for index, item in df['Voltage(V)'].iteritems():
    if df['Status'][index] == 'CC_DChg':
      if item > temp or item == temp:
        df['Voltage(V)'][index] = np.nan
      else:
        temp = item
    elif df['Status'][index] == 'CC_Chg':
      if item < temp or item == temp:
        df['Voltage(V)'][index] = np.nan
      else:
        temp = item
  return df


df = filter(df)[df['Voltage(V)'].notna()]
print(df['Cycle'].iloc[-1].astype(int) + 1)

df = df['D_Voltage(V)'] = df[(df['Status'] == 'CC_DChg') & (df['Cycle'] == 1)]['Voltage(V)']
print(df)

def transpose(df):
  for i in range(1, df['Cycle'].iloc[-1].astype(int) - 300):
    df['{} D_Voltage(V)'.format(i)] = df[(df['Status'] == 'CC_DChg') & (df['Cycle'] == i)]['Voltage(V)']
    df['{} D_Capacity(mAh)'.format(i)] = df[(df['Status'] == 'CC_DChg') & (df['Cycle'] == i)]['Voltage(V)']
    df['{} C_Voltage(V)'.format(i)] = df[(df['Status'] == 'CC_Chg') & (df['Cycle'] == i)]['Voltage(V)']
    df['{} C_Capacity(mAh)'.format(i)] = df[(df['Status'] == 'CC_Chg') & (df['Cycle'] == i)]['Voltage(V)']

  return df

#df = transpose(df).apply(lambda x: x.dropna().reset_index(drop = True))

#df.to_csv("final.csv", index = False)