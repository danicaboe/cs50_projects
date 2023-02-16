def main():
    file = input('File name: ').lower().strip()
    print(media_type(file))

def media_type(name):
    if 'gif' in name:
        return 'image/gif'
    elif 'jpeg' in name or 'jpg' in name:
        return 'image/jpeg'
    elif 'png' in name:
        return 'image/png'
    elif 'pdf' in name:
        return 'application/pdf'
    elif 'txt' in name:
        return 'text/plain'
    elif 'zip' in name:
        return 'application/zip'
    else:
        return 'application/octet-stream'

main()



    # .gif
    # .jpg
    # .jpeg
    # .png
    # .pdf
    # .txt
    # .zip
    # application/octet-stream
